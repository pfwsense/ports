PORTNAME=	snappy
PORTVERSION=	1.1.10
PORTREVISION=	0
CATEGORIES=	archivers

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Fast compressor/decompressor library
WWW=		https://google.github.io/snappy/

LICENSE=	BSD3CLAUSE

USES=		cmake compiler:c++11-lang cpe
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	SNAPPY_BUILD_TESTS SNAPPY_BUILD_BENCHMARKS
CMAKE_BUILD_TYPE=	Release
CPE_VENDOR=	google
USE_GITHUB=	yes
GH_ACCOUNT=	google
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
SUB_FILES+=	snappy.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libsnappy.so.${PORTVERSION}
	${INSTALL_DATA} ${WRKDIR}/snappy.pc ${STAGEDIR}${LOCALBASE}/libdata/pkgconfig

.include <bsd.port.mk>
