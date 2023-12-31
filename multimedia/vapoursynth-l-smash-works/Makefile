PORTNAME=	l-smash-works
DISTVERSION=	0.0-940 # git rev-list --count HEAD
DISTVERSIONSUFFIX=	-g198cc78
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMEPREFIX=	vapoursynth-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	L-SMASH source plugin for VapourSynth
WWW=		https://github.com/VFR-maniac/L-SMASH-Works/tree/master/VapourSynth

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build with FFmpeg 6 (PR 270303)

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
BUILD_DEPENDS+=	ffmpeg>=3.2,1:multimedia/ffmpeg
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		liblsmash.so:multimedia/l-smash

USE_GITHUB=	yes
GH_ACCOUNT=	VFR-maniac
GH_PROJECT=	L-SMASH-Works

USES=		gmake pkgconfig shebangfix
EXCLUDE=	VSHelper.h VSScript.h VapourSynth.h
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
WRKSRC_SUBDIR=	VapourSynth
SHEBANG_FILES=	configure
bash_CMD=	${SH}
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LD="${CC}" REV="${PORTVERSION:E}" \
		HASH="${DISTVERSIONSUFFIX:S/^-g//}"
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--extra-cflags="${CPPFLAGS} ${CFLAGS}" \
		--extra-ldflags="${LDFLAGS}" \
		--extra-libs="${LIBS}"
MAKEFILE=	GNUmakefile
MAKE_ARGS=	STRIP="${STRIP_CMD}"
CPPFLAGS+=	`pkg-config vapoursynth --cflags`
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/lib/vapoursynth
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PLIST_FILES=	lib/libvslsmashsource.so.${PORTVERSION:E}
PORTDATA=	libvslsmashsource.so
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -Ee '/CROSS/!s/^(CC|LD|REV|HASH)=.*/: $${&}/' \
		-e 's/pushd/cd/; s/popd/cd -/' \
		-e 's/-Os //; /=.*-fexcess-precision/d' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's/ -msse2 -g0//' ${WRKSRC}/${MAKEFILE}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libvslsmashsource.so.${PORTVERSION:E} \
		${STAGEDIR}${DATADIR}/libvslsmashsource.so
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
