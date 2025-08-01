#ifndef ADAPTIXCLIENT_SESSIONSTABLEWIDGET_H
#define ADAPTIXCLIENT_SESSIONSTABLEWIDGET_H

#include <main.h>
#include <Utils/CustomElements.h>

class Agent;
class AdaptixWidget;

class SessionsTableWidget : public QWidget
{
    AdaptixWidget* adaptixWidget = nullptr;

    QGridLayout*  mainGridLayout = nullptr;
    QTableWidget* tableWidget    = nullptr;
    QMenu*        menuSessions   = nullptr;
    QShortcut*    shortcutSearch = nullptr;

    QWidget*        searchWidget    = nullptr;
    QHBoxLayout*    searchLayout    = nullptr;
    QCheckBox*      checkOnlyActive = nullptr;
    QLineEdit*      inputFilter1    = nullptr;
    QLineEdit*      inputFilter2    = nullptr;
    QLineEdit*      inputFilter3    = nullptr;
    ClickableLabel* hideButton      = nullptr;

    void createUI();
    bool filterItem(const AgentData &agent) const;
    void addTableItem(const Agent* newAgent) const;

public:
    int ColumnAgentID   = 0;
    int ColumnAgentType = 1;
    int ColumnExternal  = 2;
    int ColumnListener  = 3;
    int ColumnInternal  = 4;
    int ColumnDomain    = 5;
    int ColumnComputer  = 6;
    int ColumnUser      = 7;
    int ColumnOs        = 8;
    int ColumnProcess   = 9;
    int ColumnProcessId = 10;
    int ColumnThreadId  = 11;
    int ColumnTags      = 12;
    int ColumnLast      = 13;
    int ColumnSleep     = 14;
    int ColumnCount     = 15;

    explicit SessionsTableWidget( AdaptixWidget* w );
    ~SessionsTableWidget() override;

    void AddAgentItem(Agent* newAgent) const;
    void RemoveAgentItem(const QString &agentId) const;

    void SetData() const;
    void UpdateColumnsVisible() const;
    void UpdateColumnsWidth() const;
    void ClearTableContent() const;
    void Clear() const;

public slots:
    void toggleSearchPanel() const;
    void onFilterUpdate() const;
    void handleTableDoubleClicked( const QModelIndex &index ) const;
    void handleSessionsTableMenu(const QPoint &pos );

    void actionConsoleOpen() const;
    void actionExecuteCommand();
    void actionTasksBrowserOpen() const;
    void actionMarkActive() const;
    void actionMarkInactive() const;
    void actionItemColor() const;
    void actionTextColor() const;
    void actionColorReset() const;
    void actionAgentRemove();
    void actionConsoleDelete();
    void actionItemTag() const;
    void actionItemHide() const;
    void actionItemsShowAll() const;
};

#endif
