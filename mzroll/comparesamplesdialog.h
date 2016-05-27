#ifndef COMPARESAMPLESDIALOG_H
#define COMPARESAMPLESDIALOG_H
#include "ui_comparesamplesdialog.h"
#include "mainwindow.h"

class MainWindow;
class TableDockWidget;
class BackgroundPeakUpdate;

/**
 * \class CompareSamplesDialog
 *
 * \ingroup mzroll
 *
 * \brief Class for CompareSamplesDialog to compare samples.
 *
 * This class is used for CompareSamplesDialog to compare samples.
 *
 * \author Euigen
 * \author(documentation prepared by naman)
 */

class CompareSamplesDialog: public QDialog, public Ui_CompareSamplesDialog {
Q_OBJECT

public:
	CompareSamplesDialog(QWidget *parent);
	~CompareSamplesDialog();
	void setTableWidget(TableDockWidget* w);

public slots:
	void compareSamples();
	void resetSamples();
	void compareSets();
	void cancel();
	void updateSampleList();
	vector<mzSample*> getSampleSet1() {
		return getSampleSet(filelist1);
	}
	vector<mzSample*> getSampleSet2() {
		return getSampleSet(filelist2);
	}

protected slots:
	void showEvent(QShowEvent*);

signals:
	void setProgressBar(QString, int, int);

private:
	TableDockWidget* table;
	QSet<mzSample*> samples;
	vector<mzSample*> getSampleSet(QListWidget* set);
	void shuffle(StatisticsVector<float>& groupA,
			StatisticsVector<float>& groupB);
	StatisticsVector<float> rand_scores;
	StatisticsVector<float> real_scores;
};
;

#endif
