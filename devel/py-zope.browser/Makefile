PORTNAME=	zope.browser
PORTVERSION=	2.1.0
CATEGORIES=	devel python zope
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Shared Zope Toolkit browser components
WWW=		https://pypi.org/project/zope.browser/

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
