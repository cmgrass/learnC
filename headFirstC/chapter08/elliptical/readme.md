NOTE: For a dynamic library (.so), need to add it to the "LD_LIBRARY_PATH" and export it. Otherwise, .so files are compiled without path, so linux looks first at /usr/libs, and then paths in LD_LIBRARY_PATH when it goes to link at runtime.

Example:
> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../../libs
