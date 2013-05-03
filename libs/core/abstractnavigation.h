#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <QApplication>
#include <QFileInfo>
#include <QStringList>
#include <QSettings>
#include <QKeyEvent>

class AbstractNavigation: public QObject
{
	Q_OBJECT

public:

	AbstractNavigation();
	virtual ~ AbstractNavigation();

	virtual void reset(bool triggerUpdate = true);

	//void assignCoordinateProvider(AbstractCoordinateProvider *provider);

	//void setSoftwareMapBounds(const Bounds& bounds);

	// interaction mapping

	virtual void keyPressEvent(QKeyEvent *event);
	virtual void keyReleaseEvent(QKeyEvent *event);

	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseDoubleClickEvent(QMouseEvent *event);

	virtual void wheelEvent(QWheelEvent *event);

	virtual void setCameraConfiguration(const glm::vec3 camera, const glm::vec3 center);

	// lazy matrices getters

	virtual const glm::vec3 camera() const = 0;
	virtual const glm::vec3 center() const = 0;

	virtual const glm::mat4 viewMatrix() = 0;

	virtual const glm::mat4 viewMatrixInverted() = 0;

signals:

	void cameraPositionChanged();

protected:
	mutable glm::mat4 viewmatrix;

};