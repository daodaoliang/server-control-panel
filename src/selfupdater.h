#ifndef SELFUPDATER_H
#define SELFUPDATER_H

#include "version.h"
#include "windowsapi.h"
#include "updater/downloadmanager.h"

#include "third-party/quazip/quazip/JlCompress.h"

#include <QJsonObject>
#include <QObject>

namespace Updater
{
    class SelfUpdater : public QObject
    {
        Q_OBJECT

        public:
            SelfUpdater();
            ~SelfUpdater();

            void run();
            bool updateAvailable();            

            void downloadNewVersion();
            void renameExecutable();            

            void askForRestart();

        public slots:
            void extract();

        private:
            QString getUpdateCheckURL();
            QJsonObject getVersionInfo();
            QJsonObject versionInfo;
            QString downloadFolder;

        protected:
            Downloader::DownloadManager  downloadManager;
            QNetworkAccessManager        network;

        signals:
            QJsonObject notifyUpdateAvailable(QJsonObject versionInfo);

    };

}

#endif // SELF_UPDATE_H
