PORTNAME=	qcustomplot
DISTVERSION=	2.1.1
CATEGORIES=	graphics
MASTER_SITES=	https://www.qcustomplot.com/release/${PORTVERSION}/
PKGNAMESUFFIX=	${SUFFIX}
DISTNAME=	QCustomPlot
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt C++ widget for plotting and data visualization
WWW=		https://www.qcustomplot.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.txt

USES=		compiler:c++11-lang pkgconfig qt:5
USE_QT=		core gui widgets printsupport buildtools:build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

SUFFIX=		-qt5

PLIST_FILES=	include/qcustomplot.h \
		lib/libQCustomPlot${SUFFIX}.so

do-build:
	@cd ${WRKSRC} && \
		${MOC} qcustomplot.h > qcustomplot_moc.cpp && \
		${CXX} ${CXXFLAGS} -shared -fPIC \
			-I${PREFIX}/include \
			`pkg-config --cflags --libs Qt5Core Qt5Gui Qt5Widgets Qt5PrintSupport` \
			qcustomplot.cpp \
			qcustomplot_moc.cpp \
			-o ${WRKSRC}/libQCustomPlot${SUFFIX}.so \
			-Wl,-soname,libQCustomPlot${SUFFIX}.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/qcustomplot.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libQCustomPlot${SUFFIX}.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
