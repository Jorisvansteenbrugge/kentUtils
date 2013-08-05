/* stsInfoMouse.c was originally generated by the autoSql program, which also 
 * generated stsInfoMouse.h and stsInfoMouse.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "stsInfoMouse.h"


void stsInfoMouseStaticLoad(char **row, struct stsInfoMouse *ret)
/* Load a row from stsInfoMouse table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->identNo = sqlUnsigned(row[0]);
ret->name = row[1];
ret->MGIPrimerID = sqlUnsigned(row[2]);
ret->primerName = row[3];
ret->primerSymbol = row[4];
ret->primer1 = row[5];
ret->primer2 = row[6];
ret->distance = row[7];
ret->sequence = sqlUnsigned(row[8]);
ret->MGIMarkerID = sqlUnsigned(row[9]);
ret->stsMarkerSymbol = row[10];
ret->Chr = row[11];
ret->geneticPos = atof(row[12]);
ret->stsMarkerName = row[13];
ret->LocusLinkID = sqlUnsigned(row[14]);
}

struct stsInfoMouse *stsInfoMouseLoad(char **row)
/* Load a stsInfoMouse from row fetched with select * from stsInfoMouse
 * from database.  Dispose of this with stsInfoMouseFree(). */
{
struct stsInfoMouse *ret;

AllocVar(ret);
ret->identNo = sqlUnsigned(row[0]);
ret->name = cloneString(row[1]);
ret->MGIPrimerID = sqlUnsigned(row[2]);
ret->primerName = cloneString(row[3]);
ret->primerSymbol = cloneString(row[4]);
ret->primer1 = cloneString(row[5]);
ret->primer2 = cloneString(row[6]);
ret->distance = cloneString(row[7]);
ret->sequence = sqlUnsigned(row[8]);
ret->MGIMarkerID = sqlUnsigned(row[9]);
ret->stsMarkerSymbol = cloneString(row[10]);
ret->Chr = cloneString(row[11]);
ret->geneticPos = atof(row[12]);
ret->stsMarkerName = cloneString(row[13]);
ret->LocusLinkID = sqlUnsigned(row[14]);
return ret;
}

struct stsInfoMouse *stsInfoMouseLoadAll(char *fileName) 
/* Load all stsInfoMouse from a tab-separated file.
 * Dispose of this with stsInfoMouseFreeList(). */
{
struct stsInfoMouse *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[15];

while (lineFileRow(lf, row))
    {
    el = stsInfoMouseLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct stsInfoMouse *stsInfoMouseLoadWhere(struct sqlConnection *conn, char *table, char *where)
/* Load all stsInfoMouse from table that satisfy where clause. The
 * where clause may be NULL in which case whole table is loaded
 * Dispose of this with stsInfoMouseFreeList(). */
{
struct stsInfoMouse *list = NULL, *el;
struct dyString *query = dyStringNew(256);
struct sqlResult *sr;
char **row;

sqlDyStringPrintf(query, "select * from %s", table);
if (where != NULL)
    dyStringPrintf(query, " where %s", where);
sr = sqlGetResult(conn, query->string);
while ((row = sqlNextRow(sr)) != NULL)
    {
    el = stsInfoMouseLoad(row);
    slAddHead(&list, el);
    }
slReverse(&list);
sqlFreeResult(&sr);
dyStringFree(&query);
return list;
}

struct stsInfoMouse *stsInfoMouseCommaIn(char **pS, struct stsInfoMouse *ret)
/* Create a stsInfoMouse out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new stsInfoMouse */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->identNo = sqlUnsignedComma(&s);
ret->name = sqlStringComma(&s);
ret->MGIPrimerID = sqlUnsignedComma(&s);
ret->primerName = sqlStringComma(&s);
ret->primerSymbol = sqlStringComma(&s);
ret->primer1 = sqlStringComma(&s);
ret->primer2 = sqlStringComma(&s);
ret->distance = sqlStringComma(&s);
ret->sequence = sqlUnsignedComma(&s);
ret->MGIMarkerID = sqlUnsignedComma(&s);
ret->stsMarkerSymbol = sqlStringComma(&s);
ret->Chr = sqlStringComma(&s);
ret->geneticPos = sqlFloatComma(&s);
ret->stsMarkerName = sqlStringComma(&s);
ret->LocusLinkID = sqlUnsignedComma(&s);
*pS = s;
return ret;
}

void stsInfoMouseFree(struct stsInfoMouse **pEl)
/* Free a single dynamically allocated stsInfoMouse such as created
 * with stsInfoMouseLoad(). */
{
struct stsInfoMouse *el;

if ((el = *pEl) == NULL) return;
freeMem(el->name);
freeMem(el->primerName);
freeMem(el->primerSymbol);
freeMem(el->primer1);
freeMem(el->primer2);
freeMem(el->distance);
freeMem(el->stsMarkerSymbol);
freeMem(el->Chr);
freeMem(el->stsMarkerName);
freez(pEl);
}

void stsInfoMouseFreeList(struct stsInfoMouse **pList)
/* Free a list of dynamically allocated stsInfoMouse's */
{
struct stsInfoMouse *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    stsInfoMouseFree(&el);
    }
*pList = NULL;
}

void stsInfoMouseOutput(struct stsInfoMouse *el, FILE *f, char sep, char lastSep) 
/* Print out stsInfoMouse.  Separate fields with sep. Follow last field with lastSep. */
{
fprintf(f, "%u", el->identNo);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->name);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->MGIPrimerID);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->primerName);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->primerSymbol);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->primer1);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->primer2);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->distance);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->sequence);
fputc(sep,f);
fprintf(f, "%u", el->MGIMarkerID);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->stsMarkerSymbol);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->Chr);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%f", el->geneticPos);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->stsMarkerName);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->LocusLinkID);
fputc(lastSep,f);
}
