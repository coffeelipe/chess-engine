enum class AppEventType {
    CHESS_NONE,
    CHESS_QUIT,
};

struct AppEvent
{
    AppEventType type = AppEventType::CHESS_NONE;
};
