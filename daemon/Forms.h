#ifndef _FORMS_H_
#define _FORMS_H_

#include "utils.h"
#include "logger.h"
#include "MongoDbClient.h"
#include "BsonTraverser.h"
#include "BsonPrettyPrintTraverser.h"
#include "BsonFormParseTraverser.h"

namespace JDA { 

class Forms {

	protected:
		class NextFormClientCallback : public MongoDbClient::IMongoDbClientCallback { 
			protected:
				JDA::Logger* m_p_logger;
				string s_file_name;

			public:
				NextFormClientCallback( JDA::Logger* p_logger) : m_p_logger(p_logger), s_file_name("") { }

				string getFileName(){
					return s_file_name;
				}

				void documentRecieved( const bson_t *p_bson_doc );


		}; /* class NextFormClientCallback */

		/* Attempt to grab out the cik, subject_company_name, etc... */
		class DenormalizeFormClientCallback : public MongoDbClient::IMongoDbClientCallback { 

			protected:
				JDA::Logger* m_p_logger;
				int m_i_cik;
				string m_s_subject_company_name;
				bool m_b_success;

			public:
				DenormalizeFormClientCallback( JDA::Logger* p_logger) : m_p_logger(p_logger), m_s_subject_company_name(""), m_i_cik(0) { }

				string getSubjectCompanyName(){
					return m_s_subject_company_name;
				}

				int getCik(){
					return m_i_cik;
				}


				void documentRecieved( const bson_t *p_bson_doc );

		}; /* class NextFormClientCallback */

		JDA::Logger* m_p_logger;

		//int m_i_iteration_count;
		//int m_i_byte_count;
		//int m_i_query_attempt_count;
		//int m_i_query_succeed_count;

		int m_i_ftp_debug;
		bool m_b_ftp_no_proxy;
		string m_s_ftp_proxy_user_pass;

		string m_s_db_url;
		string m_s_db_name;

		string m_s_ftp_server; // e.g., ftp.sec.gov...use to form ftp:// URL...

		JDA::MongoDbClient mongoDbClient;

	public:
		Forms(): m_i_ftp_debug(0), m_b_ftp_no_proxy(false), m_s_ftp_proxy_user_pass(""), m_s_db_url(""), m_s_db_name("") {}

		void setPLogger( JDA::Logger* p_logger ){ m_p_logger = p_logger; mongoDbClient.setPLogger(m_p_logger); }

		// Later, perhaps...
		//void setDbConnection(){}

		void setDbUrl( string sDbUrl ){ m_s_db_url = sDbUrl; mongoDbClient.setSUriStr( sDbUrl); }
		string getDbUrl(){ return m_s_db_url; }

		void setDbName( string sDbName ){ m_s_db_name = sDbName; }
		string getDbName(){ return m_s_db_name; }

		void setFtpServer( string sFtpServer){ m_s_ftp_server = sFtpServer; }
		string getFtpServer(){ return m_s_ftp_server; }

		/** NOTE: curl will read HTTP_PROXY, HTTPS_PROXY, FTP_PROXY environmental variables
		 * for proxy URL...the remainder you can set here...
		*/

		/* Set to 1 if you want extra logging output... */
		void setFtpDebug( int i_ftp_debug ){ m_i_ftp_debug = i_ftp_debug; } 
		int getFtpDebug(){ return m_i_ftp_debug; }

		/** Set to FALSE if you wish to not use a proxy even if HTTP_PROXY, HTTPS_PROXY, or FTP_PROXY environment variables are set... */
		void setFtpNoProxy( bool b_ftp_no_proxy ){ m_b_ftp_no_proxy = b_ftp_no_proxy; }
		bool getFtpNoProxy( ){ return m_b_ftp_no_proxy; }

		/** Set to "username:password", or try using just ":" for magical "NTLM" determination of username/password on Windows... */
		void setFtpProxyUserPass( string s_ftp_proxy_user_pass ){ m_s_ftp_proxy_user_pass = s_ftp_proxy_user_pass; }
		string getFtpProxyUserPass( ){ return m_s_ftp_proxy_user_pass; }

		/**
		* Load bare-bones filings into MongoDb database.forms collection from entries in EDGAR index file...
		*
		* NOTE: Immediately after runnning this, you may call getIterationCount(), getByteCount(), getQueryAttemptCount(), and getQuerySucceedCount()
		* for further information.
		*
		* @return m_i_query_succeed_count (number of successful upserts)
		*/
		int loadFromEdgarIndexUrl( const string& sEdgarIndexUrl );

		/* @throws: JDA::MongoDbClient::MongoDbException if DB error encountered. */
		int insertIndexEntry(
			const string& cik, const string& form_type, const string& date_filed, const string& file_name,
			const string& accession_number, const string& index_url
		);  

		/** Reads header of EDGAR form -- the skeleton of which has already been created in MongoDb by
		* loadFromEdgarIndexUrl()...and updates the record with information from the header.
		*
		* For example, "ftp://ftp.sec.gov/edgar/data/1403385/0000950157-15-000937.txt" or 
		*	"file:///../edgar/1016281--0001016281-15-000151--carriage-services-inc--4--2015-12-10.txt"
		*/							
		int loadFromEdgarFormUrl( const string& sEdgarFormUrl );

		/**
		* Looks in forms collection for a form that has only its bare-bones
		* "index" information, determined at the moment by...
		*     { form_processing_attempts: { "$exists" : false }
		* ...and, if found, calls loadFromEdgarFormUrl().
		*/
		int loadNextEdgarForm(); 

		/* Perform denormalization of form doc on MongoDb... */
		int denormalizeForm( const string& s_accession_number );  

		//int getIterationCount(){ return m_i_iteration_count; }
		//int getByteCount(){ return m_i_byte_count; }
		//int getQueryAttemptCount(){ return m_i_query_attempt_count; }
		//int getQuerySucceedCount(){ return m_i_query_succeed_count; }

}; /* class Forms */

} /* namespace JDA */


#endif /* #ifndef _FORMS_H_ */
