#include <Wt/WContainerWidget>

#include "UploadForm.h"

UploadForm::UploadForm(WContainerWidget )
    : WContainerWidget(parent)
{
    container = new Wt::WContainerWidget();
    root()->addWidget(container);
	fu = new Wt::WFileUpload(container);
	fu->setFileTextSize(50); // Set the maximum file size to 50 kB.
	fu->setProgressBar(new Wt::WProgressBar());
	fu->setMargin(10, Wt::Right);

	// Provide a button to start uploading.
	uploadButton = new Wt::WPushButton("Send", container);
	uploadButton->setMargin(10, Wt::Left | Wt::Right);

	out = new Wt::WText(container);

	// Upload when the button is clicked.
	uploadButton->clicked().connect(std::bind([=] () {
	    fu->upload();
	    uploadButton->disable();
	}));

	// Upload automatically when the user entered a file.
	fu->changed().connect(std::bind([=] () {
	    fu->upload();
	    uploadButton->disable();
	    out->setText("File upload is changed.");
	}));

	// React to a succesfull upload.
	fu->uploaded().connect(std::bind([=] () {
	    out->setText("File upload is finished.");
	}));

	fu->uploaded().connect(UploadForm::showDone());

	// React to a file upload problem.
	fu->fileTooLarge().connect(std::bind([=] () {
	    out->setText("File is too large.");
	}));
}

void UploadForm::showDone() {
	Wt::WMessageBox *done_uploading_alt = new Wt::WMessageBox();
   	done_uploading_alt->setText("File done uploading");
    done_uploading_alt->show();
}