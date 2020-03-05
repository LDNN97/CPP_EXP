import gym
import time
import copy
import numpy
#
# class Env(object):
#     def __init__(self, name, max_step, max_reward):
#         self.name = name
#         self.f = gym.make(name).unwrapped
#         self.n_in = self.f.observation_space.shape[0]
#         self.n_out = self.f.action_space.n
#
#         self.max_step = max_step
#         self.max_reward = max_reward
#
#     def show(self, nn, interval):
#         while True:
#             s = self.f.reset()
#             for step in range(self.max_step):
#                 self.f.render()
#                 time.sleep(interval)
#                 a = nn.get_action(s)
#                 s, _, done, _ = self.f.step(a)
#                 if done:
#                     break
#
#     @staticmethod
#     def evaluate(env, nn, n_id=None, seed=None):
#         nnn = copy.deepcopy(nn)
#         if seed is not None:
#             np.random.seed(seed)
#             noise = ES.mirror(n_id) * SIGMA * np.random.randn(len(nn.layer))
#             nnn.modify_params(noise)
#         s = env.f.reset()
#         reward = 0
#         for step in range(env.max_step):
#             a = nnn.get_action(s)
#             s, r, done, _ = env.f.step(a)
#             # modify the reward of MountainCar
#             if env.name == 'MountainCar-v0' and s[0] > -0.1:
#                 r = 0
#             reward += r
#             if done:
#                 break
#         return reward

