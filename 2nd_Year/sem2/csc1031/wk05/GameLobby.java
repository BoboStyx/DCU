import java.util.ArrayList;
import java.util.List;

interface Player {
    void joinGame();
    void leaveGame();
    void sendMessage(String message);
    void receiveMessage(String message);
    String getPlayerType();
}

abstract class AbstractPlayer implements Player {
    protected String name;
    protected GameLobby lobby;

    public AbstractPlayer(String name, GameLobby lobby) {
        this.name = name;
        this.lobby = lobby;
    }

    public String getName() {
        return name;
    }

    @Override
    public void sendMessage(String message) {
        if(getPlayerType().equals("Spectator")) {
            System.out.println("[GameLobby] Spectators cannot send messages.");
            return;
        }
		System.out.println("[" + name + "] sends: \"" + message + "\"");
        lobby.sendMessage(message, this);
    }
    @Override
    public void receiveMessage(String message) {
        System.out.println("[" + name + "] received: \"" + message + "\"");
    }
    @Override
    public void joinGame() {
        lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame() {
        lobby.removePlayer(this);
    }

    public abstract String getPlayerType();
}


class HumanPlayer extends AbstractPlayer {
    public HumanPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "HumanPlayer";
    }
}

class AIPlayer extends AbstractPlayer {
    public AIPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "AIPlayer";
    }
}

class Spectator extends AbstractPlayer {
    public Spectator(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "Spectator";
    }
}
public class GameLobby {
    private List<Player> players;

	public GameLobby() {
        players = new ArrayList<>();
    }

    public void registerPlayer(Player player) {
        players.add(player);
        System.out.println("[GameLobby] " + player.getPlayerType() + " " + ((AbstractPlayer)player).getName() + " has joined the lobby.");
    }

    public void removePlayer(Player player) {
        players.remove(player);
        System.out.println("[GameLobby] " + player.getPlayerType() + " " + ((AbstractPlayer)player).getName() + " has left the lobby.");
    }
    public void sendMessage(String message, Player sender) {
        if(sender.getPlayerType().equals("Spectator")) {
            System.out.println("[GameLobby] Spectators cannot send messages.");
            return;
        }
        System.out.println("[GameLobby] Message from " + ((AbstractPlayer)sender).getName() + ": \"" + message + "\"");
        for(Player p : players) {
            if(p != sender) {
                p.receiveMessage(message);
            }
        }
    }

    public void startMatch() {
        List<String> participantNames = new ArrayList<>();
        for (Player p : players) {
            String type = p.getPlayerType();
            if(type.equals("HumanPlayer") || type.equals("AIPlayer")) {
                participantNames.add(((AbstractPlayer)p).getName());
			}
		}
        if (participantNames.size() < 2) {
            System.out.println("[GameLobby] Not enough players to start a match.");
        } else {
            String names = String.join(", ", participantNames);
            System.out.println("[GameLobby] Starting game with players: " + names);
        }
    }
}
