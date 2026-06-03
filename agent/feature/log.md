└─(18:23:47)──> mingw32-make -j4 130 ↵ ──(Sat,May09)─┘
[ 1%] Building C object CMakeFiles/E01_BCU.dir/ied_c264_bcu.c.obj
[ 2%] Building C object CMakeFiles/E02_BCU.dir/ied_c264_bcu.c.obj
[ 3%] Building C object CMakeFiles/E01_P142.dir/ied_server_base.c.obj
[ 4%] Building C object CMakeFiles/E01_P643.dir/ied_server_base.c.obj
[ 4%] Building C object CMakeFiles/E01_BCU.dir/ied_server_base.c.obj
[ 5%] Building C object CMakeFiles/E02_BCU.dir/ied_server_base.c.obj
[ 9%] Building C object CMakeFiles/E01_P142.dir/goose_handler.c.obj
[ 9%] Building C object CMakeFiles/E02_BCU.dir/goose_handler.c.obj
[ 9%] Building C object CMakeFiles/E01_P643.dir/goose_handler.c.obj
[ 9%] Building C object CMakeFiles/E01_BCU.dir/goose_handler.c.obj
C:\goose\sas_server\goose_handler.c:109:15: error: conflicting types for 'goose_handler_init'; have 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, IedModel _)' {aka 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, struct sIedModel _)'}
109 | GooseReceiver goose_handler_init(const IedConfig _cfg,
| ^~~~~~~~~~~~~~~~~~
C:\goose\sas_server\goose_handler.c:109:15: error: conflicting types for 'goose_handler_init'; have 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, IedModel _)' {aka 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, struct sIedModel *)'}
109 | GooseReceiver goose_handler_init(const IedConfig *cfg,
| ^~~~~~~~~~~~~~~~~~
In file included from C:\goose\sas_server\goose_handler.c:6:
C:\goose\sas_server\goose_handler.h:16:15: note: previous declaration of 'goose_handler_init' with type 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, IedModel _, int (_)(struct sIedServer _, IedModel _, const IedConfig _, const char _, void _), void _)' {aka 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, struct sIedModel _, int (_)(struct sIedServer _, struct sIedModel _, const IedConfig _, const char _, void _), void _)'}
16 | GooseReceiver goose_handler_init(const IedConfig _cfg,
| ^~~~~~~~~~~~~~~~~~
C:\goose\sas_server\goose_handler.c:109:15: error: conflicting types for 'goose_handler_init'; have 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, IedModel _)' {aka 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, struct sIedModel *)'}
109 | GooseReceiver goose_handler_init(const IedConfig *cfg,
| ^~~~~~~~~~~~~~~~~~
In file included from C:\goose\sas_server\goose_handler.c:6:
C:\goose\sas_server\goose_handler.h:16:15: note: previous declaration of 'goose_handler_init' with type 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, IedModel _, int (_)(struct sIedServer _, IedModel _, const IedConfig _, const char _, void _), void _)' {aka 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, struct sIedModel _, int (_)(struct sIedServer _, struct sIedModel _, const IedConfig _, const char _, void _), void _)'}
16 | GooseReceiver goose_handler_init(const IedConfig _cfg,
| ^~~~~~~~~~~~~~~~~~
In file included from C:\goose\sas_server\goose_handler.c:6:
C:\goose\sas_server\goose_handler.h:16:15: note: previous declaration of 'goose_handler_init' with type 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, IedModel _, int (_)(struct sIedServer _, IedModel _, const IedConfig _, const char _, void _), void _)' {aka 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, struct sIedModel _, int (_)(struct sIedServer _, struct sIedModel _, const IedConfig _, const char _, void _), void *)'}
16 | GooseReceiver goose_handler_init(const IedConfig *cfg,
| ^~~~~~~~~~~~~~~~~~
C:\goose\sas_server\goose_handler.c: In function 'goose_handler_init':
C:\goose\sas_server\goose_handler.c: In function 'goose_handler_init':
C:\goose\sas_server\goose_handler.c:128:25: error: 'cmd_fn' undeclared (first use in this function)
128 | ctx->cmd_fn = cmd_fn;
| ^~~~~~
C:\goose\sas_server\goose_handler.c: In function 'goose_handler_init':
C:\goose\sas_server\goose_handler.c:128:25: error: 'cmd_fn' undeclared (first use in this function)
128 | ctx->cmd_fn = cmd_fn;
| ^~~~~~
C:\goose\sas_server\goose_handler.c:109:15: error: conflicting types for 'goose_handler_init'; have 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, IedModel _)' {aka 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, struct sIedModel _)'}
109 | GooseReceiver goose_handler_init(const IedConfig _cfg,
| ^~~~~~~~~~~~~~~~~~
C:\goose\sas_server\goose_handler.c:128:25: note: each undeclared identifier is reported only once for each function it appears in
C:\goose\sas_server\goose_handler.c:128:25: error: 'cmd_fn' undeclared (first use in this function)
128 | ctx->cmd_fn = cmd_fn;
| ^~~~~~
C:\goose\sas_server\goose_handler.c:128:25: note: each undeclared identifier is reported only once for each function it appears in
In file included from C:\goose\sas_server\goose_handler.c:6:
C:\goose\sas_server\goose_handler.h:16:15: note: previous declaration of 'goose_handler_init' with type 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, IedModel _, int (_)(struct sIedServer _, IedModel _, const IedConfig _, const char _, void _), void _)' {aka 'struct sGooseReceiver _(const IedConfig _, struct sIedServer _, struct sIedModel _, int (_)(struct sIedServer _, struct sIedModel _, const IedConfig _, const char _, void _), void *)'}
16 | GooseReceiver goose_handler_init(const IedConfig *cfg,
| ^~~~~~~~~~~~~~~~~~
C:\goose\sas_server\goose_handler.c:128:25: note: each undeclared identifier is reported only once for each function it appears in
C:\goose\sas_server\goose_handler.c:129:25: error: 'ctx_ptr' undeclared (first use in this function)
129 | ctx->ctx_ptr = ctx_ptr;
| ^~~~~~~
C:\goose\sas_server\goose_handler.c:129:25: error: 'ctx_ptr' undeclared (first use in this function)
129 | ctx->ctx_ptr = ctx_ptr;
| ^~~~~~~
C:\goose\sas_server\goose_handler.c:129:25: error: 'ctx_ptr' undeclared (first use in this function)
129 | ctx->ctx_ptr = ctx_ptr;
| ^~~~~~~
C:\goose\sas_server\goose_handler.c: In function 'goose_handler_init':
C:\goose\sas_server\goose_handler.c:128:25: error: 'cmd_fn' undeclared (first use in this function)
128 | ctx->cmd_fn = cmd_fn;
| ^~~~~~
C:\goose\sas_server\goose_handler.c:128:25: note: each undeclared identifier is reported only once for each function it appears in
C:\goose\sas_server\goose_handler.c:129:25: error: 'ctx_ptr' undeclared (first use in this function)
129 | ctx->ctx_ptr = ctx_ptr;
| ^~~~~~~
mingw32-make[2]: **_ [CMakeFiles\E01_P142.dir\build.make:139: CMakeFiles/E01_P142.dir/goose_handler.c.obj] Error 1
mingw32-make[2]: _** [CMakeFiles\E01_BCU.dir\build.make:139: CMakeFiles/E01_BCU.dir/goose_handler.c.obj] Error 1
mingw32-make[1]: **_ [CMakeFiles\Makefile2:201: CMakeFiles/E01_P142.dir/all] Error 2
mingw32-make[2]: _** [CMakeFiles\E01_P643.dir\build.make:139: CMakeFiles/E01_P643.dir/goose_handler.c.obj] Error 1
mingw32-make[1]: **_ Waiting for unfinished jobs....
mingw32-make[2]: _** [CMakeFiles\E02_BCU.dir\build.make:139: CMakeFiles/E02_BCU.dir/goose_handler.c.obj] Error 1
mingw32-make[1]: **_ [CMakeFiles\Makefile2:137: CMakeFiles/E01_BCU.dir/all] Error 2
mingw32-make[1]: _** [CMakeFiles\Makefile2:169: CMakeFiles/E01_P643.dir/all] Error 2
mingw32-make[1]: **_ [CMakeFiles\Makefile2:233: CMakeFiles/E02_BCU.dir/all] Error 2
mingw32-make: _** [Makefile:90: all] Error 2
