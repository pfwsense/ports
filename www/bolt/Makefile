PORTNAME=	bolt
PORTVERSION=	2.2.24
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	https://bolt.cm/distribution/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sophisticated, lightweight & simple CMS
WWW=		https://bolt.cm/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe php:web
CPE_VENDOR=	${PORTNAME}cms

NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	ctype curl dom gd mbstring simplexml tokenizer

PLIST_SUB+=	WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
