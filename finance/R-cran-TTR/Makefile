PORTNAME=	TTR
DISTVERSION=	0.24.3
PORTREVISION=	1
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Technical Trading Rules
WWW=		https://cran.r-project.org/web/packages/TTR/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-xts>=0.10.0:math/R-cran-xts \
		R-cran-zoo>0:math/R-cran-zoo \
		R-cran-curl>0:ftp/R-cran-curl
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
