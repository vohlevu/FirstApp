/*
 * FirstApp.h
 *
 *  Created on: 05-05-2014
 *      Author: vohlevu
 */

#ifndef FIRSTAPP_H_
#define FIRSTAPP_H_
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <string>

std::string DownloadJSON(std::string URL);
int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in);

#endif /* FIRSTAPP_H_ */
