PORTNAME=	viridis
PORTVERSION=	0.6.4
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Default Color Maps from 'matplotlib'
WWW=		https://cran.r-project.org/web/packages/viridis/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-ggplot2>=1.0.1:graphics/R-cran-ggplot2 \
		R-cran-gridExtra>0:graphics/R-cran-gridExtra \
		R-cran-viridisLite>=0.4.0:graphics/R-cran-viridisLite
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
