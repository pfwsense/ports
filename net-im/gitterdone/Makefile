PORTNAME=	gitterdone
PORTVERSION=	201710031257
PORTREVISION=	4
CATEGORIES=	net-im

MAINTAINER=	jt@ixsystems.com
COMMENT=	Gitter Client based on Qt5
WWW=		https://github.com/trueos/gitterdone

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lang gl qmake qt:5 shebangfix tar:xz
USE_QT=		core gui network linguist:build \
		buildtools:build widgets webkit svg
USE_GL+=	gl
USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=	yes

WRKSRC_SUBDIR=	src-qt5

QMAKE_ARGS=	CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_TAGNAME=	23eaadb70baeffb22ab035e08fc4675907707590

.include <bsd.port.mk>
