PORTNAME=	qtbuilder
PORTVERSION=	${PYQTBUILDER_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQTBUILDER}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYQTBUILDER_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The PEP 517 compliant PyQt build system
WWW=		https://www.riverbankcomputing.com/software/pyqt-builder/

USES=		python pyqt:5
USE_PYTHON=	autoplist concurrent distutils flavors py3kplist
USE_PYQT=	#

NO_ARCH=	yes

.include <bsd.port.mk>
