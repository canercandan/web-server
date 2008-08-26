/**
 * @file URIParser.h
 * @brief 
 * @note 
 */
class URIParser 
{
public:
  URIParser (Consumer* );
  bool readHierPart ();
  bool readAbsoluteURI ();
  bool readAbsoluteURIOpt ();
  bool readScheme ();
  bool readAuthority ();
  bool readAuthorityOpt1 ();
  bool readAuthorityOpt2 ();
  bool readUserInfo ();
  bool readHost (std::string& extract);
  bool readPort (std::string& extract);
  bool readIPLiteral ();
  bool readIPvFuture ();
  bool readIPv6address ();
  bool readIPv4address ();
  bool readDecOctet ();
  bool readRegName ();
  bool readPath ();
  bool readPathAbempty ();
  bool readPathAbemptyPart2 ();
  bool readPathAbsolute ();
  bool readPathAbsoluteOpt ();
  bool readPathAbsolutePart2 ();
  bool readPathNoScheme ();
  bool readPathNoSchemePart2 ();
  bool readPathRootless ();
  bool readPathRootlessPart2 ();
  bool readPathEmpty ();
  bool readSegment ();
  bool readSegmentNz ();
  bool readSegmentNzNc ();
  bool readPchar ();
  bool readQuery ();
  bool readFragment ();
  bool readPctEncoded ();
  bool readUnreserved ();
  bool readReserved ();
  bool readGenDelims ();
  bool readSubDelims ();
};
