PORTNAME=	seqwish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.9
CATEGORIES=	biology
MASTER_SITES=	https://github.com/ekg/seqwish/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Alignment to variation graph inducer
WWW=		https://github.com/ekg/seqwish

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_CXXFLAGS=	-fopenmp
OPENMP_BROKEN_OFF=	https://github.com/ekg/seqwish/issues/114

.include <bsd.port.mk>
