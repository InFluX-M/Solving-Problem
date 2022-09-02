import pygame

pygame.init()
screen = pygame.display.set_mode((300, 300))
screen.fill((255, 255, 255))
pygame.display.update()

size = 1
color = (0, 0, 0)

while True:

    inp = input()

    if "change size" in inp:
        size = int(inp.split(" ")[2])

    elif "change color" in inp:
        color = (int(inp.split(" ")[2]), int(inp.split(" ")[3]), int(inp.split(" ")[4]))

    elif "draw line" in inp:
        pygame.draw.line(screen, color, (int(inp.split(" ")[2]), int(inp.split(" ")[3])), (int(inp.split(" ")[4]), int(inp.split(" ")[5])), size)
        pygame.display.update()

    elif "draw circle" in inp:
        pygame.draw.circle(screen, color, (int(inp.split(" ")[2]), int(inp.split(" ")[3])), int(inp.split(" ")[4]), size)
        pygame.display.update()

    elif "draw polygon" in inp:
        ls = list(inp.split(" ")[2:])
        point_ls = []
        for i in range(0, len(ls), 2):
            point_ls.append((int(ls[i]), int(ls[i+1])))

        pygame.draw.polygon(screen, color, point_ls, size)

    elif "end drawing" in inp:
        break

pygame.display.update()
pygame.image.save(screen, 'draw.png')