PORTNAME=	gpicker
DISTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SAVANNAH

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program allowing to quickly pick a file in a large project
WWW=		https://savannah.nongnu.org/projects/gpicker

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-runtime gmake gnome pkgconfig
USE_GNOME=	gtk20 cairo gdkpixbuf2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gpicker bin/gpicker-simple man/man1/gpicker-simple.1.gz man/man1/gpicker.1.gz

.include <bsd.port.mk>
