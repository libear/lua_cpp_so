如果是.cpp文件，在luaopen_mylib一定要加 extern "C", 否则导出的函数会被重命名，切记切记
