PORTNAME=	update
PORTVERSION=	23.7
CATEGORIES=	sysutils
PKGNAMEPREFIX=	${GH_ACCOUNT}-

MAINTAINER=	franco@pfwsense.org
COMMENT=	PFWsense update utilities
WWW=		https://pfwsense.org/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS+=	libucl.so:textproc/libucl

USES=		ssl

MAKE_ENV=	UPDATE_RELEASE=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	${CATEGORIES:[1]}
#GH_TAGNAME=	f731208

.include <bsd.port.mk>
