#ifndef XENIA_UI_QT_SETTINGS_PANE_H_
#define XENIA_UI_QT_SETTINGS_PANE_H_

#include <QWidget>

#include "xenia/base/cvar.h"
#include "xenia/config.h"
#include "xenia/ui/qt/themeable_widget.h"
#include "xenia/config.h"
#include "xenia/ui/qt/settings/widgets/settings_widget.h"
#include "xenia/ui/qt/settings/widgets/settings_radio_button.h"
#include "xenia/ui/qt/settings/widgets/settings_combobox.h"
#include "xenia/ui/qt/settings/widgets/settings_text_edit.h"
#include "xenia/ui/qt/settings/widgets/settings_checkbox.h"

namespace xe {
namespace ui {
namespace qt {

class SettingsPane : public Themeable<QWidget> {
  Q_OBJECT
 public:
  explicit SettingsPane(QChar glyph, const QString& title,
                        QWidget* parent = nullptr)
      : Themeable<QWidget>("SettingsPane", parent),
        glyph_(glyph),
        title_(title) {}

  virtual ~SettingsPane() = default;

  QChar glyph() const { return glyph_; }
  const QString& title() const { return title_; }

  QWidget* widget() const { return widget_; }

  virtual void Build() = 0;

 protected:
  void set_widget(QWidget* widget) { widget_ = widget; }


 private:
  QChar glyph_;
  QString title_;
  QWidget* widget_ = nullptr;
};

}  // namespace qt
}  // namespace ui
}  // namespace xe

#endif