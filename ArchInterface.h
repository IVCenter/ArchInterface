#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <time.h>
//#include <tchar.h>
#include <cstdlib>
#include <libpq-fe.h>
//Inorder to compile with GCC you must also include the library: libpq.lib
#include <string>
#include <sstream>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <mxml.h>

//for Windows
#ifdef _WIN32
#include <direct.h>
#endif

//#include <include/curl/curl.h>
//#include "shapelib/shapefil.h"

using namespace std;

PGconn *connectDB(string param);

PGresult *queryPG(string query, string serverName);

vector< vector<string> > queryPostGIS(string query, string list, string type, string srid);

void newtablePG(string table);

void dropTable(string table,string server);

vector<string> splitSTR(string tmp, char lim);

vector<string> fileIntoArray(const char* file);

vector< vector<string> > parseConfigFile();

void importCSV(string sfile, string table, string type, string delim);

void importPointData(string table, vector< vector<string> > data );

void importPolygonData(string table, vector< vector<string> > data );

void importTableData(string table, vector< vector<string> > data, vector<string> fields, string server);

void importCouchDbTableData(string table, vector< vector<string> > data, string server);

void importGeomData(string table, vector< vector<string> > data, vector<string> fields, string server);

int newStdTable(string tableS, vector<string> fields, string type, string server);

int newPointTable(string tableS);

int newPolygonTable(string tableL);

void runDemo();

void importDemos();

void commandLineParse(int argc, char *argv[]);

void parametersHelp();

vector< vector<string> > getArrayofQueryFunction(string table, string where);

void outputPostGISarray(vector< vector<string> > rowdata, string list);

void kmlFromQuery(string table, string where, string name);

void makePointKML(vector< vector<string> > rowdata, string list, string where, string q_name);

void makePolygonKML(vector< vector<string> > rowdata, string list, string where, string q_name, string table);

void outputShpCSV(vector< vector<string> > rowdata, string list, string q_name, string table);

string outputDescription(vector< vector<string> > rowdata, string list, int row);

string tableType(string table);

void printQueryResults(string table, string where);

void listTables(string table);

void getDistinctQuery(string table);

void syncLogon(string table);

void syncTable(string table);

string connectParam(string serverName);

vector< vector<string> > parseWhere(string where);

bool preventOverwrite(string name);

string getNxtQuery(string type);

string generateQName(string where, string type);

mxml_node_t * getTree(string filename);

vector<string> getNodeArray(string filename, const char* node_name);

void appendStringXML(string filename, const char* node_name, string str);

void resetStringXML(string filename, const char* node_name, string str);

void renameQfile(string file, string name);

void deleteQfile(string name);

vector<string> makePolyhedron(string temp, string locus, string table, string type);

double findBottom(string locus, string table, string typec);

string getLocusColor(string locus,string table, string type);

string getLocusName(string locus, string table);

void convertKML(string filename);

string outputDescriptionBase(string gid, string the_geom, string list);

string getTimeStamp();

void insertRow(string table, string list);

vector< vector<string> > outputTable(string table, string server);

vector< vector<string> > getCouchDBTable(string table, string server);

void syncCouchDBandPg(string table, string server);

string getTableType(string table);

void storeCSVtable(string table, string server);

void replaceTable(string table, string server, string recent);

void addSyncTable(string table, string server, string recent);

void appendTable(string table, string server, string recent, int gidLocal1, int gidCentral1);

vector< vector<string> > outputTableSelect(string table, string server, PGresult *res);

vector<string> shpDump(int argc, char ** argv);

vector< vector<string> > dbfDump(int argc, char ** argv);

void kmlFromShp(char *shapefile,string type,string table);

string dbfHeaders(char *shapefile);

vector<string> makePolyhedronShp(string temp, string gid, string table,string type, vector<string> rowdata);

vector<string> selectRamp(string type);

vector<double> setColorRamp(int divider,double max,double min);

string rgbRamp(int divider, double value,vector<double> divs, vector<string> ramp);

void testCode();

string getWorkingDir();

string getColumnsString(string table);

void outputTableDatatoGeoJson(string table, string server, vector<vector<string> > data);

vector<string > getCouchDbDocs(string table);

int tableExists(string table, string server);

string getCouchDbDoc(string table, string docId);

int getCouchDbDocCount(string table);

vector< vector<string> > queryStandardTable(string query, string table, string server);

void createDefaultTable(string table, string server, string type, string fieldList);

int tableCheck(string table, string server);

void defaultInstall(string server);

bool fileExists(string file);
