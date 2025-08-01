#ifndef BRIDGEAPP_H
#define BRIDGEAPP_H

#include <QObject>
#include <QString>
#include <QJSValue>

class AxScriptEngine;
class Command;

class BridgeApp : public QObject {
Q_OBJECT
    AxScriptEngine* scriptEngine;
    QWidget*        widget;

public:
    explicit BridgeApp(AxScriptEngine* scriptEngine, QObject* parent = nullptr);
    ~BridgeApp() override;
    AxScriptEngine* GetScriptEngine() const;

public slots:
    QJSValue agents() const;
    QJSValue agent_info(const QString &id, const QString &property) const;
    void     agent_set_color(const QJSValue& agents, const QString &background, const QString &foreground, const bool reset);
    void     agent_set_impersonate(const QString &id, const QString &impersonate, const bool elevated);
    void     agent_set_mark(const QJSValue& agents, const QString &mark);
    void     agent_set_tag(const QJSValue& agents, const QString &tag);
    QString  arch(const QString &id) const;
    QString  bof_pack(const QString &types, const QJSValue &args);
    void     copy_to_clipboard(const QString &text);
    void     console_message(const QString &id, const QString &message, const QString &type = "", const QString &text = "");
    QJSValue credentials() const;
    void     credentials_add(const QString &username, const QString &password, const QString &realm = "", const QString &type = "password", const QString &tag = "", const QString &storage = "manual", const QString &host = "");
    QObject* create_command(const QString &name, const QString &description, const QString &example = "", const QString &message = "");
    QObject* create_commands_group(const QString &name, const QJSValue& array);
    void     execute_alias(const QString &id, const QString &cmdline, const QString &command, const QString &message = "", const QJSValue &hook = QJSValue()) const;
    void     execute_browser(const QString &id, const QString &command) const;
    void     execute_command(const QString &id, const QString &command, const QJSValue &hook = QJSValue()) const;
    QString  file_basename(const QString &path) const;
    bool     file_exists(const QString &path) const;
    QString  file_read(QString path) const;
    QString  format_time(const QString &format, const int &time) const;
    QJSValue interfaces() const;
    bool     is64(const QString &id) const;
    bool     isadmin(const QString &id) const;
    void     log(const QString &text);
    void     log_error(const QString &text);
    void     open_agent_console(const QString &id);
    void     open_access_tunnel(const QString &id, bool socks4, bool socks5, bool lportfwd, bool rportfwd);
    void     open_browser_files(const QString &id);
    void     open_browser_process(const QString &id);
    void     open_remote_terminal(const QString &id);
    QString  prompt_open_file(const QString &caption = "Select file", const QString &filter = QString());
    QString  prompt_open_dir(const QString &caption = "Select directory");
    QString  prompt_save_file(const QString &filename, const QString &caption = "Select file", const QString &filter = QString());
    void     register_commands_group(QObject* obj, const QJSValue& agents, const QJSValue& os, const QJSValue& listeners);
    void     script_import(const QString &path);
    void     script_load(const QString &path);
    void     script_unload(const QString &path);
    QString  script_dir();
    void     show_message(const QString &title, const QString &text);
    int      ticks();

signals:
    void consoleMessage(const QString &msg);
    void consoleError(const QString &msg);
    void engineError(const QString &msg);
};

#endif
