PORTNAME=	promises
PORTVERSION=	1.2.0.1
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Abstractions for Promise-Based Asynchronous Programming
WWW=		https://cran.r-project.org/web/packages/promises/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-later>0:devel/R-cran-later \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-magrittr>0:devel/R-cran-magrittr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
