PORTNAME=	smbprotocol
PORTVERSION=	1.10.1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interact with a server using the SMB 2/3 Protocol
WWW=		https://github.com/jborean93/smbprotocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyspnego>=0:security/py-pyspnego@${PY_FLAVOR}

USES=		python pycryptography:run
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
