PORTNAME=	gigabase
PORTVERSION=	3.91
PORTREVISION=	9
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION} \
		http://www.garret.ru/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-Relational Database Management System
WWW=		http://www.garret.ru/gigabase.html

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USES=		autoreconf dos2unix gmake libtool
DOS2UNIX_FILES=	Makefile.in configure.in *.cpp *.h
USE_GCC=	yes
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes

post-build:
	${STRIP_CMD} ${WRKSRC}/.libs/*.so

.include <bsd.port.mk>
