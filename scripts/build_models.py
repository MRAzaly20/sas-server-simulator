#!/usr/bin/env python3
import os
import glob
import subprocess
import shutil

def main():
    # Define paths relative to this script
    script_dir = os.path.dirname(os.path.abspath(__file__))
    base_dir = os.path.abspath(os.path.join(script_dir, ".."))
    
    ieds_dir = os.path.join(base_dir, "ieds")
    src_models_dir = os.path.join(base_dir, "src", "models")
    
    # Path to genmodel.jar based on the provided relative path
    genmodel_jar = os.path.abspath(os.path.join(base_dir, "..", "..", "libiec61850", "tools", "model_generator", "genmodel.jar"))

    print(f"Using Genmodel JAR: {genmodel_jar}")
    print(f"Source CIDs: {ieds_dir}")
    print(f"Output Directory: {src_models_dir}\n")

    if not os.path.exists(genmodel_jar):
        print(f"ERROR: Could not find genmodel.jar at {genmodel_jar}")
        print("Please check the path to libiec61850.")
        return

    if not os.path.exists(ieds_dir):
        print(f"ERROR: The directory {ieds_dir} does not exist.")
        return
        
    os.makedirs(src_models_dir, exist_ok=True)

    # Find all .cid files in the ieds directory
    cid_files = glob.glob(os.path.join(ieds_dir, "*.cid"))
    
    if not cid_files:
        print(f"No .cid files found in {ieds_dir}.")
        return

    print(f"Found {len(cid_files)} CID files. Starting generation...\n")

    # genmodel.jar outputs to static_model.c and static_model.h in the working directory
    # Therefore, we run the subprocess with cwd=src_models_dir, then rename and modify the files.
    for cid_path in cid_files:
        basename = os.path.basename(cid_path)
        name_without_ext = os.path.splitext(basename)[0]
        model_variable_name = f"model_{name_without_ext}"

        print(f"Generating C models for {basename} (variable: {model_variable_name})...")

        # Command: java -jar genmodel.jar <absolute_cid_path>
        cmd = [
            "java",
            "-jar",
            genmodel_jar,
            cid_path
        ]

        try:
            subprocess.run(cmd, cwd=src_models_dir, check=True, capture_output=True, text=True)
            
            static_c = os.path.join(src_models_dir, "static_model.c")
            static_h = os.path.join(src_models_dir, "static_model.h")
            
            new_c = os.path.join(src_models_dir, f"{name_without_ext}.c")
            new_h = os.path.join(src_models_dir, f"{name_without_ext}.h")
            
            if os.path.exists(static_c):
                with open(static_c, "r", encoding="utf-8") as f:
                    c_content = f.read()
                
                # Replace include and variable names
                c_content = c_content.replace('static_model.h', f'{name_without_ext}.h')
                c_content = c_content.replace('iedModel', model_variable_name)
                
                with open(new_c, "w", encoding="utf-8") as f:
                    f.write(c_content)
                os.remove(static_c)
                
            if os.path.exists(static_h):
                with open(static_h, "r", encoding="utf-8") as f:
                    h_content = f.read()
                
                # Replace variable names and header guards
                h_content = h_content.replace('iedModel', model_variable_name)
                h_content = h_content.replace('STATIC_MODEL_H_', f'{name_without_ext.upper()}_H_')
                h_content = h_content.replace('STATIC_MODEL_H', f'{name_without_ext.upper()}_H')
                
                with open(new_h, "w", encoding="utf-8") as f:
                    f.write(h_content)
                os.remove(static_h)
            
            print(f"  [OK] Generated {name_without_ext}.c and {name_without_ext}.h")
        except subprocess.CalledProcessError as e:
            print(f"  [ERROR] Failed to generate for {basename}")
            print(f"          {e.stderr.strip()}")

    print("\nCopying .cid files to src/models/ ...")
    for cid_path in cid_files:
        dest_path = os.path.join(src_models_dir, os.path.basename(cid_path))
        shutil.copy2(cid_path, dest_path)
        print(f"  [OK] Copied {os.path.basename(cid_path)}")

    print("\nBuild complete! All C/H files and CIDs are now in src/models.")

if __name__ == "__main__":
    main()
