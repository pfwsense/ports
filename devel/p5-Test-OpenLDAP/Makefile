PORTNAME=	Test-OpenLDAP
PORTVERSION=	0.05
PORTREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to creates temp instance of slapd to run tests against
WWW=		https://metacpan.org/release/Test-OpenLDAP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Data-UUID>0:devel/p5-Data-UUID \
	p5-perl-ldap>0:net/p5-perl-ldap
BUILD_DEPENDS=	${RUN_DEPENDS}

NO_ARCH=	yes
USES=		ldap:server perl5
USE_PERL5=	configure

CONFIGURE_ENV=	PATH=${PATH}:${PREFIX}/libexec

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|/usr/lib/openldap|${LOCALBASE}/libexec|' \
		${WRKSRC}/lib/Test/OpenLDAP.pm
	${RM} ${WRKSRC}/lib/Test/OpenLDAP.pm.bak \
		${WRKSRC}/lib/Test/OpenLDAP.pm.orig

.include <bsd.port.mk>
