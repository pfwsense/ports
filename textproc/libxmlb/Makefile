PORTNAME=	libxmlb
DISTVERSION=	0.3.11
CATEGORIES=	textproc

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library to help create and query binary XML blobs
WWW=		https://github.com/hughsie/libxmlb

LICENSE=	LGPL21

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libstemmer.so:textproc/snowballstemmer \
		libzstd.so:archivers/zstd

USES=		gnome meson pkgconfig localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	hughsie
USE_GNOME=	glib20 introspection:build

MESON_ARGS=	-Dstemmer=true

.include <bsd.port.mk>
