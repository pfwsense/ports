PORTNAME=	pam-modules
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/pam-modules/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of modules for PAM
WWW=		https://puszcza.gnu.org.ua/software/pam-modules/pam-modules.html

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=		libtool

USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-fshadow

OPTIONS_DEFINE=	GROUPMEMBER MYSQL REGEX PGSQL SYSLOG
OPTIONS_DEFAULT=	GROUPMEMBER REGEX SYSLOG
OPTIONS_SUB=	yes

GROUPMEMBER_CONFIGURE_ENABLE=	groupmember
GROUPMEMBER_DESC=	Build pam_groupmember

MYSQL_CONFIGURE_ENABLE=	mysql
MYSQL_DESC=	Build pam_mysql
MYSQL_USES=	mysql

PGSQL_CONFIGURE_ENABLE=	pgsql
PGSQL_DESC=	Build pam_pgsql
PGSQL_USES=	pgsql
PGSQL_VARS=	WANT_PGSQL=client

SYSLOG_CONFIGURE_ENABLE=	log
SYSLOG_DESC=	Build pam_log

REGEX_CONFIGURE_ENABLE=	regex
REGEX_DESC=	Build pam_regex

INFO=	pam-modules

.include <bsd.port.options.mk>

.include <bsd.port.mk>
