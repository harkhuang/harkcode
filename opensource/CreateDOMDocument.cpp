/*
 * ===========================================================================
 *
 *       Filename:  CreateXML.cpp
 *
 *    Description:  This is an example of the use of Xerces-C++ operation XML.
 *
 *        Version:  1.0
 *        Created:  02/28/2010 11:48:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  huabo (caodaijun), caodaijun@feinno.com
 *        Company:  feinno
 *
 * ===========================================================================
 */
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/framework/MemBufFormatTarget.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>

#include <string>

#if defined(XERCES_NEW_IOSTREAMS)
#include <iostream>
#else
#include <iostream.h>
#endif

XERCES_CPP_NAMESPACE_USE
class XStr
{
        public:
                XStr(const char* const toTranscode)
                {
                        fUnicodeForm = XMLString::transcode(toTranscode);
                }
                ~XStr()
                {
                        XMLString::release(&fUnicodeForm);
                }
                const XMLCh* unicodeForm() const
                {
                        return fUnicodeForm;
                }
        private:
                XMLCh*   fUnicodeForm;
};

#define X(str) XStr(str).unicodeForm()

std::string basic_string =
"<basic>"
"<corp_name>abcd</corp_name>"
"<corp_code></corp_code>"
"<c0></c0>"
"<short_name></short_name>"
"<calling_code></calling_code>"
"<legal_representative></legal_representative>"
"<address></address>"
"<zip></zip>"
"<telephone></telephone>"
"<fax></fax>"
"<contact></contact>"
"<proportion_code></proportion_code>"
"<logo_crc></logo_crc>"
"<employee_portrait_crc></employee_portrait_crc>"
"<group_portrait_crc></group_portrait_crc>"
"<createtime></createtime>"
"<opentime></opentime>"
"<province_code></province_code>"
"<vgop_code></vgop_code>"
"<org_version></org_version>"
"<source_code></source_code>"
"<client_dept_version></client_dept_version>"
"<version_id></version_id>"
"<contact_mp></contact_mp>"
"</basic>";

std::string rules_string = 
"<rules>"
"<order_flag></order_flag>"
"<demo_flag></demo_flag>"
"<useroperate_limit></useroperate_limit>"
"<emp_portrait_flag></emp_portrait_flag>"
"<iplmt></iplmt>"
"<dept_auth_switch></dept_auth_switch>"
"<sms_block></sms_block>"
"<sms_begin></sms_begin>"
"<sms_end></sms_end>"
"<edit_status></edit_status>"
"<expire_time></expire_time>"
"</rules>";

std::string accounts_string = 
"<accounts>"
"<scale_code></scale_code>"
"<customer_manager></customer_manager>"
"<manager_phone></manager_phone>"
"<deposit_bank></deposit_bank>"
"<bank_accounts></bank_accounts>"
"<password_paper_id></password_paper_id>"
"<group_code></group_code>"
"<sms_code></sms_code>"
"<meeting_code></meeting_code>"
"<fee_code></fee_code>"
"<cycle_code></cycle_code>"
"<sharedisk_code></sharedisk_code>"
"<sp_status></sp_status>"
"<updatetime></updatetime>"
"</accounts>";

int main(int argC, char*argV[])
{
        // Initialize the XML4C2 system.
        try
        {
                XMLPlatformUtils::Initialize();/*init*/
        }
        catch(const XMLException& toCatch)
        {
                char *pMsg = XMLString::transcode(toCatch.getMessage());
                XERCES_STD_QUALIFIER cerr << "Error during Xerces-c Initialization.\n"
                        << "  Exception message:"
                        << pMsg;
                XMLString::release(&pMsg);
                return 1;
        }

        DOMImplementation* impl =  DOMImplementationRegistry::getDOMImplementation(X("LS"));/**Implementation*/
        DOMLSSerializer*   theSerializer = ((DOMImplementationLS*)impl)->createLSSerializer();/** createLSSerializer*/
        DOMLSOutput       *theOutputDesc = ((DOMImplementationLS*)impl)->createLSOutput();/**createLSOutput*/
        MemBufFormatTarget* target = new MemBufFormatTarget();
        theOutputDesc->setByteStream(target);

        if (impl != NULL)
        {
                try
                {
                        DOMDocument* doc = impl->createDocument(
                                        0,                    // root element namespace URI. /**可用资源标识*/
                                        X("corporation"),     // root element name /**a large companny*/
                                        0);                   // document type object (DTD). /**mem mannager mode object*/
                        doc->setXmlStandalone(true);

                        DOMElement*  rootElem = doc->getDocumentElement();
                        rootElem->setAttribute(X("xmlns"), X("com:cmcc:corporation"));
                        rootElem->setAttribute(X("xmlns:xsi"), X("http://www.w3.org/2001/XMLSchema-instance"));
                        rootElem->setAttribute(X("xsi:schemaLocation"), X("com:cmcc:corporation corporation.xsd"));

                        //add node
                        DOMElement*  prodElem = doc->createElement(X("eid"));
                        rootElem->appendChild(prodElem);

                        DOMText* prodDataVal = doc->createTextNode(X("100000"));
                        prodElem->appendChild(prodDataVal);

                        XercesDOMParser* parser = new XercesDOMParser();

                        //add basic child
                        MemBufInputSource* basic_mem = new MemBufInputSource(
                                        (const XMLByte* )basic_string.c_str(),
                                        strlen(basic_string.c_str()),
                                        "basic",
                                        false);
                        parser->parse( *basic_mem );
                        DOMDocument* xmlDoc = parser->getDocument();
                        DOMElement* basic_root = xmlDoc->getDocumentElement();
                        DOMNode* newnode = doc->importNode((DOMNode* )basic_root, true);
                        rootElem->appendChild(newnode); 
                        delete basic_mem;

                        //add the rules child
                        MemBufInputSource* rules_mem = new MemBufInputSource(
                                        (const XMLByte* )rules_string.c_str(),
                                        rules_string.length(),
                                        "rules",
                                        false);
                        parser->parse( *rules_mem );
                        xmlDoc = parser->getDocument();
                        DOMElement* rules_root = xmlDoc->getDocumentElement();
                        newnode = doc->importNode((DOMNode* )rules_root, true);
                        rootElem->appendChild(newnode);
                        delete rules_mem;

                        //add the accounts child
                        MemBufInputSource* accounts_mem = new MemBufInputSource(
                                        (const XMLByte* )accounts_string.c_str(),
                                        accounts_string.length(),
                                        "accounts",
                                        false);
                        parser->parse( *accounts_mem );
                        xmlDoc = parser->getDocument();
                        DOMElement* accounts_root = xmlDoc->getDocumentElement();
                        newnode = doc->importNode((DOMNode* )accounts_root, true);
                        rootElem->appendChild(newnode);
                        delete accounts_mem;

                        theSerializer->write(doc, theOutputDesc);
                        std::cout<< target->getRawBuffer()<< std::endl;

                        delete target;
                        delete parser;
                        theOutputDesc->release();
                        theSerializer->release();
                        doc->release();
                }
                catch(const OutOfMemoryException&)
                {
                        XERCES_STD_QUALIFIER cerr << "OutOfMemoryException" << XERCES_STD_QUALIFIER endl;
                }
                catch (const DOMException& e)
                {
                        XERCES_STD_QUALIFIER cerr << "DOMException code is:  " << e.code << XERCES_STD_QUALIFIER endl;
                }
                catch (...)
                {
                        XERCES_STD_QUALIFIER cerr << "An error occurred creating the document" << XERCES_STD_QUALIFIER endl;
                }
        }
        else
        {
                XERCES_STD_QUALIFIER cerr << "Requested implementation is not supported" << XERCES_STD_QUALIFIER endl;
        }

        XMLPlatformUtils::Terminate();
        return 0;
}
