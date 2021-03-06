#ifndef _FORMS_UTILS_H_
#define _FORMS_UTILS_H_

#include <string>
#include <iostream>
#include <memory> // shared_ptr<>, etc.
#include <vector>
#include <regex>
using namespace std;


#include "utils.h"
#include "logger.h"

namespace JDA { 

class FormsUtils {

	public:

		static int debug;

		enum DownloadWindowType { DAY, EVENING, WEEKEND }; 

		// Mirrors DownloadWindowType enum for easy conversion to std::string...
		static const char* downloadWindowTypeEnumStrings[];

		static string downloadWindowTypeToString( DownloadWindowType downloadWindowType ){
			const char* sWho = "::downloadWindowTypeToString";
			(void)sWho; /* unused...? who says...? */
			return downloadWindowTypeEnumStrings[ downloadWindowType ];
		}

		DownloadWindowType in_which_download_window(
			int evening_start_hour,
			int evening_end_hour,
			int hour = -1,
			int day_of_week = -1
		);

		/**
		* e.g.,
		* accessionNumberFromFilePath("edgar/data/1000275/0001214659-14-000507.txt") = "0001214659-14-000507"
		* accessionNumberFromFilePath("edgar/data--1000275--0001214659-14-000507.txt") = "0001214659-14-000507"
		* accessionNumberFromFilePath("0001214659-14-000507.txt") = "0001214659-14-000507"
		* accessionNumberFromFilePath("0001214659-14-000507.xml") = "0001214659-14-000507"
		* accessionNumberFromFilePath("0001214659-14-000507") = "0001214659-14-000507"
		*/	
		static string accessionNumberFromFilePath( const string& sFilePath );

		/** Right now blindly adds dashes to an 8 character input string, or if input is not 8 characters,
		* returns the input unchanged.  We may decide to add some error checking later.
		*
		* e.g.,
		* 	FormsUtils::isoDateFromYyyyMmDd("20160606") return "2016-06-06"
		* 	FormsUtils::isoDateFromYyyyMmDd("HELLOABC") return "HELL-OA-BC" -- since it doesn't check for numerical input.
		*   FormsUtils::isoDateFromYyyyMmDd("201606") return "201606" -- or the original input, because the input string is not 8 characters...
		*/
		static string isoDateFromYyyyMmDd( const string& sYyyyMmDd );

		/**
		* e.g.,
		* cikFromUrl("ftp://ftp.sec.gov/edgar/data/1066107/0001047469-15-001027.txt") => 1066107 
		* cikFromUrl("file:///../edgar/ftp.sec.gov--edgar--data--1066107--POSASR--has-a-gazillion-filers--0001047469-15-001027.txt") => 1066107
		*
		*/
		static string cikFromUrl( const string& sUrl );

		/* e.g., single_quote_escape("The word is \"Groucho\"")
		*    returns "The word is \\\"Groucho\\\"", which can be
		*    embedded in JSON...
		*    info = { "quote" : "The word is \\\"Groucho\\\"" }
		*/
		static string double_quote_escape(const string& input);

		/* Can later move this to JDA::Utils... */
		static bool nuttinButNumbers( const string& s_input );

		static string regex_error_code_to_string( std::regex_constants::error_type le_error_code );

}; /* class FormsUtils */


} /* namespace JDA */


#endif /* #ifndef _FORMS_UTILS_H_ */
