PORTNAME=	robotframework-databaselibrary
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Utilities meant for Robot Frameworks usage
WWW=		https://franz-see.github.io/Robotframework-Database-Library/

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:devel/py-robotframework@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	franz-see
GH_PROJECT=	Robotframework-Database-Library

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
