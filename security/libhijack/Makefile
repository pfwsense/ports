PORTNAME=	libhijack
PORTVERSION=	0.8.1
CATEGORIES=	security

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Runtime process infection made easy
WWW=		https://github.com/SoldierX/libhijack

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

USE_GITHUB=	yes
GH_ACCOUNT=	SoldierX
GH_TAGNAME=	44f28bf2f220bb794a8f3302c6291823b23b43bb

USE_LDCONFIG=	yes

PLIST_FILES=	include/hijack.h \
		lib/libhijack.so \
		lib/libhijack.so.2 \
		sbin/hijack

do-install: # the original install fails: https://github.com/SoldierX/libhijack/issues/6
	${INSTALL_DATA} ${WRKSRC}/include/hijack.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libhijack/obj/libhijack.so* ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/hijack/obj/hijack ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
