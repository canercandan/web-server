/**
 * @file IBuild.h
 * @brief 
 * @note 
 */
class IBuild 
{
public:
  ~IBuild ();
  void accept (IModule* );
  const std::string& getMethod ();
  const std::string& getPath ();
  const mapKey& getCacheControl ();
  const listString& getConnection ();
  const std::string& getDate ();
  const mapKey& getPragma ();
  const listString& getTrailer ();
  const listString& getTransferEncoding ();
  const listVP& getUpgrade ();
  const listWarning& getWarning ();
  const listType& getAccept ();
  const listString& getAcceptCharset ();
  const listString& getAcceptEncoding ();
  const listString& getAcceptLangage ();
  const std::string& getAuthorization ();
  const mapKey& getExcept ();
  const std::string& getFrom ();
  const Host& getHost ();
  const listString& getIfMatch ();
  const listString& getAllow ();
  const listString& getContentEncoding ();
  const listString& getContentLangage ();
  const int& getContentLength ();
  const std::string& getContentLocation ();
  const std::string& getContentMd5 ();
  const std::string& getContentRange ();
  const listType& getContentType ();
  const std::string& getExpires ();
  const std::string& getLastModified ();
  void setMethod (const std::string& );
  void setPath (const std::string& );
  void addCacheControl (const std::string& key,
			const std::string& value);
  void setDate (const std::string& );
  void addPragma (const std::string& key,
		  const std::string& value);
  void addTrailer (const std::string& trailer);
  void addTransferEncoding (const std::string& encoding);
  void addUpgrade (const VersionProtocol& versionProtocol);
  void addWarning (const Warning& warning);
  void addAccept (const Type& type);
  void addAcceptCharset (const std::string& charset);
  void addAcceptEncoding (const std::string& encoding);
  void addAcceptLangage (const std::string& lang);
  void setAuthorization (const std::string& digest);
  void addExcept (const std::string& key,
		  const std::string& value);
  void setFrom (const std::string& );
  void addIfMatch (const std::string& match);
  void addAllow (const std::string& allow);
  void addContentEncoding (const std::string& encoding);
  void addContentLangage (const std::string& lang);
  void setContentLength (const int& );
  void setContentLocation (const std::string& );
  void setContentMd5 (const std::string& );
  void setContentRange (const std::string& );
  void addContentType (const Type& type);
  void setExpires (const std::string& );
  void setLastModifies (const std::string& );
};
