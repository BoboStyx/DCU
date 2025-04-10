import java.util.ArrayList;
import java.util.List;

interface Player {
    void joinGame();
    void leaveGame();
    void sendMessage(String message);
    void receiveMessage(String message);
	String getName();
    String getPlayerType();
}

abstract class AbstractPlayer implements Player {
    protected String name;
    protected GameLobby lobby;

    public AbstractPlayer(String name, GameLobby lobby) {
        this.name = name;
        this.lobby = lobby;
    }

	@Override
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

class AdminPlayer extends AbstractPlayer {
    public AdminPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "AdminPlayer";
    }

    public void kickPlayer(String name) {
        lobby.kickPlayer(name, this);
    }
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


	class GameLobby {
    private List<Player> players;

	public GameLobby() {
        players = new ArrayList<>();
    }

    public void registerPlayer(Player player) {
        players.add(player);
        System.out.println("[GameLobby] " + player.getPlayerType() + " " + player.getName() + " has joined the lobby.");
    }

    public void removePlayer(Player player) {
        players.remove(player);
        System.out.println("[GameLobby] " + player.getPlayerType() + " " + player.getName() + " has left the lobby.");
    }

	void kickPlayer(String name, AdminPlayer admin){
		for (Player p : players){
			if (p.getName() == name && p.getPlayerType() != "AdminPlayer"){
				System.out.println("[GameLobby] Admin " + admin.getName() + " kicked " + p.getPlayerType() + " " + name + " from the lobby.");
				removePlayer(p);
				return;
			}
		}
		System.out.println("[GameLobby] Player " + name + " not found.");
	}
    public void sendMessage(String message, Player sender) {
        if(sender.getPlayerType().equals("Spectator")) {
            System.out.println("[GameLobby] Spectators cannot send messages.");
            return;
        }
        System.out.println("[GameLobby] Message from " + sender.getName() + ": \"" + message + "\"");
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
                participantNames.add(p.getName());
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

class PlayerFactory {
    public static Player createPlayer(String type, String name, GameLobby lobby) {
        switch (type.toLowerCase()) {
            case "human":
                return new HumanPlayer(name, lobby);
            case "ai":
                return new AIPlayer(name, lobby);
            case "spectator":
				return new Spectator(name, lobby);
			case "admin":
				return new AdminPlayer(name, lobby);
       }
		return new HumanPlayer(name, lobby);
    }
}
