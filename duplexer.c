/*TODO*/
//Find the number of pages
//Find the job id of the original print job
//
//

#include <stdio.h>
#include <cups/cups.h>

// Search for printer
// Generate a list of printers to select from

int print_dest(void *user_data, unsigned flags, cups_dest_t *dest)
{
  if (dest->instance)
    printf("%s/%s\n", dest->name, dest->instance);
  else
    puts(dest->name);

  return (1);
}

int main(void)
{
  cupsEnumDests(CUPS_DEST_FLAGS_NONE, 1000, NULL, 0, 0, print_dest, NULL);

  return (0);
}
// Above subject to rewrite

//Connect to printer
char resource[256];
http_t *my_http = cupsConnectDest(my_dest, CUPS_DEST_FLAGS_DEVICE,
                               30000, NULL, resource,
                               sizeof(resource), NULL, NULL);

// Listen for jobs for printer (Probably shouldn't have a while for one line)	
while (int cupsGetJobs2(CUPS_HTTP_DEFAULT,
						NULL?, my_destination,
						0, CUPS_WHICHJOBS_ACTIVE) == 0);

//Put job on hold
ipp_t *request = ippNewRequest(IPP_OP_HOLD_NEW_JOBS);
const char *printer_uri = cupsGetOption("device-uri",
                                        dest->num_options,
                                        dest->options);

ippAddString(request, IPP_TAG_OPERATION, IPP_TAG_URI,
             "printer-uri", NULL, printer_uri);

ipp_t *response = cupsDoRequest(my_http, request, resource);

/* Details from response. Might not factor this in just yet... will need to rework it for job status

ipp_attribute_t *attr;

if ((attr = ippFindAttribute(response, "printer-state",
                             IPP_TAG_ENUM)) != NULL)
{
  printf("printer-state=%s\n",
         ippEnumString("printer-state", ippGetInteger(attr, 0)));
}
else
  puts("printer-state=unknown");

if ((attr = ippFindAttribute(response, "printer-state-message",
                             IPP_TAG_TEXT)) != NULL)
{
  printf("printer-state-message=\"%s\"\n",
         ippGetString(attr, 0, NULL)));
}

if ((attr = ippFindAttribute(response, "printer-state-reasons",
                             IPP_TAG_KEYWORD)) != NULL)
{
  int i, count = ippGetCount(attr);

  puts("printer-state-reasons=");
  for (i = 0; i < count; i ++)
    printf("    %s\n", ippGetString(attr, i, NULL)));
}
*/

//ippDelete(response);

	// Get information on the job
cups_job_t *my_jobs;
int no_of_jobs = cupsGetJobs2(my_http, *my_jobs, 
							const char *name/*REPLACE WITH NAME OF DESTINATION*/, 
							0,CUPS_WHICHJOBS_ALL);
							//Returns the number of jobs as well as the job list (I think...)

	// Create new  job structures

int job_id = no_of_jobs+1;
int job_id = 0;
int num_options = 0;
cups_option_t *odd_options = NULL;
cups_option_t *even_options = NULL;

if (cupsCreateDestJob(CUPS_HTTP_DEFAULT, dest, info,
                      &job_id, "My Document", num_options,
                      options) == IPP_STATUS_OK)
  printf("Created job: %d\n", job_id);
else
  printf("Unable to create job: %s\n",
         cupsLastErrorString());

//Get number of pages
int num_pages;
//Create for loop to append odd numbers in that page range 
char odd_range [65536]
//Create for loop to append even numbers in that page range 
char even_range [65536]

// Create new  document structures
	
	// Allocate odd page numbers to first
cupsAddOption(page-ranges, odd_range, 1, *odd_options);
	//Allocate even page numbers next
cupsAddOption(page-ranges, even_ranges, 1, *even_options);

// Send the first job
	void print first part(/*arguments*/){
	FILE *fp = fopen("filename.pdf", "rb");
	size_t bytes;
	char buffer[65536];

	if (cupsStartDestDocument(CUPS_HTTP_DEFAULT, dest, info,
   		                       job_id, "filename.pdf", 1, odd_options,
   		                       /*int last_document*/) == HTTP_STATUS_CONTINUE)
	{
	  while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0)
   		 if (cupsWriteRequestData(CUPS_HTTP_DEFAULT, buffer,
                             bytes) != HTTP_STATUS_CONTINUE)
   		   break;

	  if (cupsFinishDestDocument(CUPS_HTTP_DEFAULT, dest,
                             info) == IPP_STATUS_OK)
	    puts("Document send succeeded.");
	  else
	    printf("Document send failed: %s\n",
	           cupsLastErrorString());
	}
	fclose(fp);
}

// Wait until button is pressed

// Send the second job
void print second part(/*arguments*/){
	FILE *fp = fopen("filename.pdf", "rb");
	size_t bytes;
	char buffer[65536];

	if (cupsStartDestDocument(CUPS_HTTP_DEFAULT, dest, info,
   		                       job_id, "filename.pdf", 1, even_options,
   		                       /*int last_document*/) == HTTP_STATUS_CONTINUE)
	{
	  while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0)
   		 if (cupsWriteRequestData(CUPS_HTTP_DEFAULT, buffer,
                             bytes) != HTTP_STATUS_CONTINUE)
   		   break;

	  if (cupsFinishDestDocument(CUPS_HTTP_DEFAULT, dest,
                             info) == IPP_STATUS_OK)
	    puts("Document send succeeded.");
	  else
	    printf("Document send failed: %s\n",
	           cupsLastErrorString());
	}
	fclose(fp);
}

// Cancel original job
cupsCancelDestJob(my_http, my_dest, int job_id/*???*/);
