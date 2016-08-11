#include <Wt/WApplication>

#include "UploadForm.h"

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
  Wt::WApplication *app = new Wt::WApplication(env);

  app->setTitle("Piccasable");

  app->useStyleSheet("css/hangman.css");

  new UploadForm(app->root());

  return app;
}


int main(int argc, char **argv)
{
  return Wt::WRun(argc, argv, &createApplication);
}