PORTNAME=	sqlparse
PORTVERSION=	0.4.4
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-validating SQL parser for Python
WWW=		https://github.com/andialbrecht/sqlparse

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	sqlparse/cli.py

.include <bsd.port.mk>
