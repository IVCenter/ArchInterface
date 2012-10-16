Readme for ArchInterface

Install Windows:

ArchInterface.exe is precompiled for Windows and will excecute in current directory.
Curl.exe is also compiled and is only required by ArchInterface for CouchDB queries.

Compile from Source:
ArchInterface requires Pgsql and MxML these are included in the same named folders.
You can use the CodeBlocks project to immediately compile.

Install Linux:
--make using any standard compilers and linking your psgsql and mxml libs--

Running ArchInterface

1. Rename default_config.ini to config.ini. Edit config.ini to change settings for your PostGIS server
If you only have one server only edit the Local Settings even if it is served
from a remote location. Central is only for when you want to sync to seperate
servers.

2. Run: ArchInterface -i
-This will test your connection to determine if PostGIS is properly installed.
-If the initial checks are passed it will then install key tables for ArchInterface and some test data to further test everything is working.

3. Run: ArchInterface -h to get a detailed help on the various commands that can be run.
