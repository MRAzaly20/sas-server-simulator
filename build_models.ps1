Write-Host "Running CID generator..."
python scripts/generate_per_ied_cid.py

Write-Host "Copying CIDs to src/models..."
Copy-Item "ieds\*.cid" -Destination "src\models\" -Force

Write-Host "Regenerating static C models..."
Set-Location "src\models"
foreach ($cid in Get-ChildItem "*.cid") {
    Write-Host "Processing $($cid.Name)"
    java -jar "..\..\..\libiec61850\tools\model_generator\genmodel.jar" $cid.Name "model_$($cid.BaseName)"
}
Set-Location "..\.."

Write-Host "Build complete!"
