/* soapSSOIdentityProviderSOAPBindingProxy.cpp
   Generated by gSOAP 2.7.14 from josso-1.2.h
   Copyright(C) 2000-2009, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>

#include "soapSSOIdentityProviderSOAPBindingProxy.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif


SSOIdentityProviderSOAPBindingProxy::SSOIdentityProviderSOAPBindingProxy()
{	SSOIdentityProviderSOAPBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

SSOIdentityProviderSOAPBindingProxy::SSOIdentityProviderSOAPBindingProxy(const struct soap &soap)
{	soap_copy_context(this, &soap);
	SSOIdentityProviderSOAPBindingProxy_init(soap.imode, soap.omode);
}

SSOIdentityProviderSOAPBindingProxy::SSOIdentityProviderSOAPBindingProxy(soap_mode iomode)
{	SSOIdentityProviderSOAPBindingProxy_init(iomode, iomode);
}

SSOIdentityProviderSOAPBindingProxy::SSOIdentityProviderSOAPBindingProxy(soap_mode imode, soap_mode omode)
{	SSOIdentityProviderSOAPBindingProxy_init(imode, omode);
}

void SSOIdentityProviderSOAPBindingProxy::SSOIdentityProviderSOAPBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns4", "urn:org:josso:gateway:ws:1.2:wsdl/SSOIdentityProviderSOAPBinding", NULL, NULL},
	{"ns5", "urn:org:josso:gateway:ws:1.2:wsdl/SSOIdentityManagerSOAPBinding", NULL, NULL},
	{"ns6", "urn:org:josso:gateway:ws:1.2:wsdl/SSOSessionManagerSOAPBinding", NULL, NULL},
	{"ns3", "urn:org:josso:gateway:ws:1.2:protocol", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	if (!this->namespaces)
		this->namespaces = namespaces;
}

SSOIdentityProviderSOAPBindingProxy::~SSOIdentityProviderSOAPBindingProxy()
{ }

void SSOIdentityProviderSOAPBindingProxy::soap_noheader()
{	header = NULL;
}

const SOAP_ENV__Fault *SSOIdentityProviderSOAPBindingProxy::soap_fault()
{	return this->fault;
}

const char *SSOIdentityProviderSOAPBindingProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *SSOIdentityProviderSOAPBindingProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int SSOIdentityProviderSOAPBindingProxy::soap_close_socket()
{	return soap_closesock(this);
}

void SSOIdentityProviderSOAPBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void SSOIdentityProviderSOAPBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *SSOIdentityProviderSOAPBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int SSOIdentityProviderSOAPBindingProxy::resolveAuthenticationAssertion(ns3__ResolveAuthenticationAssertionRequestType *ns3__ResolveAuthenticationAssertionRequest, ns3__ResolveAuthenticationAssertionResponseType *ns3__ResolveAuthenticationAssertionResponse)
{	struct soap *soap = this;
	struct __ns4__resolveAuthenticationAssertion soap_tmp___ns4__resolveAuthenticationAssertion;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://replace";
	soap->encodingStyle = NULL;
	soap_tmp___ns4__resolveAuthenticationAssertion.ns3__ResolveAuthenticationAssertionRequest = ns3__ResolveAuthenticationAssertionRequest;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns4__resolveAuthenticationAssertion(soap, &soap_tmp___ns4__resolveAuthenticationAssertion);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns4__resolveAuthenticationAssertion(soap, &soap_tmp___ns4__resolveAuthenticationAssertion, "-ns4:resolveAuthenticationAssertion", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns4__resolveAuthenticationAssertion(soap, &soap_tmp___ns4__resolveAuthenticationAssertion, "-ns4:resolveAuthenticationAssertion", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__ResolveAuthenticationAssertionResponse)
		return soap_closesock(soap);
	ns3__ResolveAuthenticationAssertionResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns3__ResolveAuthenticationAssertionResponse->soap_get(soap, "ns3:ResolveAuthenticationAssertionResponse", "ns3:ResolveAuthenticationAssertionResponseType");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap, 0);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SSOIdentityProviderSOAPBindingProxy::assertIdentityWithSimpleAuthentication(ns3__AssertIdentityWithSimpleAuthenticationRequestType *ns3__AssertIdentityWithSimpleAuthenticationRequest, ns3__AssertIdentityWithSimpleAuthenticationResponseType *ns3__AssertIdentityWithSimpleAuthenticationResponse)
{	struct soap *soap = this;
	struct __ns4__assertIdentityWithSimpleAuthentication soap_tmp___ns4__assertIdentityWithSimpleAuthentication;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://replace";
	soap->encodingStyle = NULL;
	soap_tmp___ns4__assertIdentityWithSimpleAuthentication.ns3__AssertIdentityWithSimpleAuthenticationRequest = ns3__AssertIdentityWithSimpleAuthenticationRequest;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns4__assertIdentityWithSimpleAuthentication(soap, &soap_tmp___ns4__assertIdentityWithSimpleAuthentication);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns4__assertIdentityWithSimpleAuthentication(soap, &soap_tmp___ns4__assertIdentityWithSimpleAuthentication, "-ns4:assertIdentityWithSimpleAuthentication", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns4__assertIdentityWithSimpleAuthentication(soap, &soap_tmp___ns4__assertIdentityWithSimpleAuthentication, "-ns4:assertIdentityWithSimpleAuthentication", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__AssertIdentityWithSimpleAuthenticationResponse)
		return soap_closesock(soap);
	ns3__AssertIdentityWithSimpleAuthenticationResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns3__AssertIdentityWithSimpleAuthenticationResponse->soap_get(soap, "ns3:AssertIdentityWithSimpleAuthenticationResponse", "ns3:AssertIdentityWithSimpleAuthenticationResponseType");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap, 0);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SSOIdentityProviderSOAPBindingProxy::globalSignoff(ns3__GlobalSignoffRequestType *ns3__GlobalSignoffRequest, ns3__GlobalSignoffResponseType *ns3__GlobalSignoffResponse)
{	struct soap *soap = this;
	struct __ns4__globalSignoff soap_tmp___ns4__globalSignoff;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://replace";
	soap->encodingStyle = NULL;
	soap_tmp___ns4__globalSignoff.ns3__GlobalSignoffRequest = ns3__GlobalSignoffRequest;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns4__globalSignoff(soap, &soap_tmp___ns4__globalSignoff);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns4__globalSignoff(soap, &soap_tmp___ns4__globalSignoff, "-ns4:globalSignoff", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns4__globalSignoff(soap, &soap_tmp___ns4__globalSignoff, "-ns4:globalSignoff", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns3__GlobalSignoffResponse)
		return soap_closesock(soap);
	ns3__GlobalSignoffResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns3__GlobalSignoffResponse->soap_get(soap, "ns3:GlobalSignoffResponse", "ns3:GlobalSignoffResponseType");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap, 0);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
