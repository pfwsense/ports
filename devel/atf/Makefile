PORTNAME=	atf
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/jmmv

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	C, C++ and shell libraries to write ATF-compliant test programs
WWW=		https://github.com/jmmv/atf/

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool
USE_CXXSTD=	gnu++11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_DEFAULT=TEST

.include <bsd.port.options.mk>

MAKE_FLAGS+=	atf_pkgconfigdir=${PREFIX}/libdata/pkgconfig
.if empty(PORT_OPTIONS:MDOCS)
MAKE_FLAGS+=	doc_DATA=
.endif
.if empty(PORT_OPTIONS:MTEST)
PLIST_SUB+=	TEST="@comment "
.else
PLIST_SUB+=	TEST=
.endif

post-install:
.if empty(PORT_OPTIONS:MTEST)
	@${RM} -r ${STAGEDIR}${PREFIX}/tests
.endif

.include <bsd.port.mk>
