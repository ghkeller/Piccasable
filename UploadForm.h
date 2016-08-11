#ifndef UPLOAD_H_
#define UPLOAD_H_

#include <functional>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WFileUpload>
#include <Wt/WProgressBar>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WMessageBox>

class UploadForm : public Wt::WContainerWidget
{
public:
  UploadForm(Wt::WContainerWidget *parent = 0);

private:
  Wt::WContainerWidget *container;
  Wt::WFileUpload *fu;
  Wt::WPushButton *uploadButton;
  Wt::WText *out;

  void showDone();
};

#endif //HANGMANGAME_H_