/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2013, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#include "FirstApp.h"
using namespace std;
#define KNRM  "\033[0m"
#define KRED  "\033[31m"
#define KGRN  "\033[32m"
#define KYEL  "\033[33m"
#define KBLU  "\033[34m"
#define KMAG  "\033[35m"
#define KCYN  "\033[36m"
#define KWHT  "\033[37m"
#include <curl/curl.h>
/*struct string {
  char *ptr;
  size_t len;
};*/
//void init_string(struct string *s);
//size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s);
int main(void)
{
	std:string s = DownloadJSON("http://google.com.vn");;
	printf("\n%s'%s'%s\n", KGRN, s.data(), KNRM);
	return 0;
}
std::string DownloadJSON(std::string URL)
{
    CURL *curl;
    CURLcode res;
    std:string DownloadedResponse;
    struct curl_slist *headers=NULL; // init to NULL is important
    //std::ostringstream oss;
    curl_slist_append(headers, "Accept: application/json");
    curl_slist_append( headers, "Content-Type: application/json");
    curl_slist_append( headers, "charsets: utf-8");
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPGET,1);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &DownloadedResponse);
        res = curl_easy_perform(curl);

        if (CURLE_OK == res)
        {
            char *ct;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            if((CURLE_OK == res) && ct)
                return DownloadedResponse;
        }
    }

}

int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{

    // Is there anything in the buffer?
    if (buffer_in != NULL)
    {
        // Append the data to the buffer
        buffer_in->append(data, size * nmemb);

        return size * nmemb;
    }

    return 0;

}/*
void init_string(struct string *s) {
  s->len = 0;
  s->ptr = (char*)malloc(s->len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}
size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = (char*)realloc(s->ptr, new_len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}*/
