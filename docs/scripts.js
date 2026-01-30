// Simple tab switching for embedded sites
document.addEventListener('DOMContentLoaded', () => {
  const tabs = document.querySelectorAll('.tab');
  const sections = document.querySelectorAll('.frame-wrap');

  function activate(targetId) {
    sections.forEach(sec => {
      if (sec.id === targetId) {
        sec.classList.remove('hidden');
      } else {
        sec.classList.add('hidden');
      }
    });
    tabs.forEach(t => t.classList.toggle('active', t.dataset.target === targetId));
  }

  tabs.forEach(tab => {
    tab.addEventListener('click', () => {
      activate(tab.dataset.target);
    });
  });

  // initialize: show first tab
  activate('site-1');
});
