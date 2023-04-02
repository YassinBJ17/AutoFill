ECHO OFF
ECHO suppress the useless .o and .d files for manual code
cd ..\..\LIBUTI_gen\gen
DEL /F /Q /S *.d
DEL /F /Q /S *.o

