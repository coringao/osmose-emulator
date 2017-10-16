/*
 * Copyright holder 2001-2011 Vedder Bruno.
 * Work continued by 2016-2017 Carlos Donizete Froes [a.k.a coringao]
 *
 * This file is part of Osmose, a Sega Master System/Game Gear software
 * emulator.
 *
 * Osmose is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * Osmose is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Osmose.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Many thanks to Vedder Bruno, the original author of Osmose Emulator.
 *
 */

#ifndef QGLIMAGE_H
#define QGLIMAGE_H

#include <QtOpenGL>
#include <QGLWidget>
#include <QMutex>
#include <QMutexLocker>
#include <QGLFormat>

class QGLImage : public QGLWidget
{
	Q_OBJECT;
	
public:
	QGLImage(QWidget *parent = 0, int w = 320, int h = 240, QGL::FormatOptions f = QGL::DirectRendering);
	~QGLImage();
	void blit(unsigned int *source);
	int getTextureWidth() { return textureWidth;}
	int getTextureHeight() { return textureHeight;}
	bool isBilinearFiltering() { return bilinearFiltering;}
	bool isNearestNeighboorFiltering() { return (!bilinearFiltering);}
	
public slots:
	void resolutionChanged(int newx, int newy);
	void bilinearFilteringOn();
	void nearestNeighboorFilteringOn();

	
protected:
	void resizeGL(int width, int height);
	void paintGL();
	void initializeGL();

private:
	void setupViewport(int w, int h);
	int viewPortWidth;
	int viewPortHeight;
	int textureWidth;
	int textureHeight;
	int adjustedTextureWidth;
	int adjustedTextureHeight;
	float glTextCoordX;
	float glTextCoordY;
	bool bilinearFiltering;
	
	// Texture used to render the Quad.
	QMutex textureBufferMutex;
	GLuint textureName[1];
	unsigned int *textureBuffer;
	void adjustTextureDimension(int w, int h);
	int getNearestGreaterPowerOfTwo(int size);
};

#endif	// QGLIMAGE_H
