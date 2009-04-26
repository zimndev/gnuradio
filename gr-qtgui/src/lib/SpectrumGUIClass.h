#ifndef SPECTRUM_GUI_CLASS_HPP
#define SPECTRUM_GUI_CLASS_HPP

//#include <mutexClass.hpp>
#include <qwidget.h>
#include <qapplication.h>
#include <qlabel.h>
#include <qslider.h>
#include <spectrumUpdateEvents.h>

//#include <Windowing.hpp>

class SpectrumDisplayForm;
#include <spectrumdisplayform.h>

#include <cmath>

#include <complex>
#include <vector>
#include <string>

class SpectrumGUIClass
{
public:
  SpectrumGUIClass(const uint64_t maxDataSize, const uint64_t fftSize,
		   const double newStartFrequency, const double newStopFrequency);
  ~SpectrumGUIClass();
  void Reset();

  void OpenSpectrumWindow(QWidget*,
			  const bool frequency=true, const bool waterfall=true,
			  const bool waterfall3d=true, const bool time=true,
			  const bool constellation=true);
  void SetDisplayTitle(const std::string);

  bool GetWindowOpenFlag();
  void SetWindowOpenFlag(const bool);

  void SetFrequencyRange(const double, const double, const double);
  double GetStartFrequency()const;
  double GetStopFrequency()const;
  double GetCenterFrequency()const;

  void UpdateWindow(const bool, const std::complex<float>*,
		    const uint64_t, const float*,
		    const uint64_t, const float*,
		    const uint64_t, const double,
		    const timespec, const bool);

  float GetPowerValue()const;
  void SetPowerValue(const float);

  int GetWindowType()const;
  void SetWindowType(const int);

  int GetFFTSize()const;
  int GetFFTSizeIndex()const;
  void SetFFTSize(const int);

  timespec GetLastGUIUpdateTime()const;
  void SetLastGUIUpdateTime(const timespec);

  unsigned int GetPendingGUIUpdateEvents()const;
  void IncrementPendingGUIUpdateEvents();
  void DecrementPendingGUIUpdateEvents();
  void ResetPendingGUIUpdateEvents();

  static const long MAX_FFT_SIZE = /*1048576*/32768;
  static const long MIN_FFT_SIZE = 1024;

  QWidget* qwidget();

protected:

private:

  //MutexClass* _windowStateLock;
  int64_t _dataPoints;
  std::string _title;
  double _centerFrequency;
  double _startFrequency;
  double _stopFrequency;
  float _powerValue;
  bool _windowOpennedFlag;
  int _windowType;
  int64_t _lastDataPointCount;
  int _fftSize;
  timespec _lastGUIUpdateTime;
  unsigned int _pendingGUIUpdateEventsCount;
  int _droppedEntriesCount;
  bool _fftBuffersCreatedFlag;

  SpectrumDisplayForm* _spectrumDisplayForm;

  std::complex<float>* _fftPoints;
  double* _realTimeDomainPoints;
  double* _imagTimeDomainPoints;
};

#endif /* SPECTRUM_GUI_CLASS_HPP */
