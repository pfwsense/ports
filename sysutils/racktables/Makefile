PORTNAME=	racktables
DISTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES?=	sysutils www
MASTER_SITES=	SF/${PORTNAME}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	RackTables-${DISTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Server room asset management suite
WWW=		https://www.racktables.org/

LICENSE=	GPLv2

NO_BUILD=	yes
RACKHOME?=	www/racktables

PORTEXAMPLES=	cleanup_ldap_cache.php init-sample-racks.sql syncdomain.php

USES=		cpe shebangfix php:web,flavors perl5 python:run
NO_ARCH=	yes
USE_PERL5=	run
SHEBANG_FILES=	gateways/*
CPE_VENDOR=	racktables_project

USE_PHP=	bcmath gd mbstring mysqli pdo_mysql session
SUB_FILES=	pkg-message
PLIST_SUB=	WWWDIR_REL=${WWWDIR_REL} WWWDIR=${WWWDIR}
WWWUSER?=	www
WWWGRP?=	www

OPTIONS_DEFINE=	LDAP SNMP CURL PCNTL EXAMPLES
PCNTL_DESC=	pcntl Support
LDAP_USE=	PHP=ldap
SNMP_USE=	PHP=snmp
CURL_USE=	PHP=curl
PCNTL_USE=	PHP=pcntl

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -type f -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/wwwroot ${STAGEDIR}${WWWDIR}/gateways
	(cd ${WRKSRC} && ${COPYTREE_SHARE} wwwroot ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC} && ${COPYTREE_BIN} gateways ${STAGEDIR}${WWWDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
